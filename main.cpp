#include <Magick++.h>
#include <iostream>
#include <vector>
#include <string>

#define UNUSED(x) (void)(x)
#define COLOR_RESET   "\033[0m"
#define COLOR_GREEN   "\033[32m"

using namespace std;
using namespace Magick;

void showHelp()
{
    cout << "Supported сommands:" << endl;
    cout << COLOR_GREEN << "Load image file:" << COLOR_RESET << endl;
    cout << "load <name> <filename>" << endl;
    cout << "ld <name> <filename>" << endl;
    cout << COLOR_GREEN << "Save image file:" << COLOR_RESET << endl;
    cout << "store <name> <filename>" << endl;
    cout << "s <name> <filename>" << endl;
    cout << COLOR_GREEN << "Blur image:" << COLOR_RESET << endl;
    cout << "blur <from_name> <to_name> <size>" << endl;
    cout << COLOR_GREEN << "Resize image:" << COLOR_RESET << endl;
    cout << "resize <from_name> <to_name> <new_width> <new_width>" << endl;
    cout << COLOR_GREEN << "Show help:" << COLOR_RESET << endl;
    cout << "help" << endl;
    cout << "h" << endl;
    cout << COLOR_GREEN << "Exit:" << COLOR_RESET << endl;
    cout << "exit" << endl;
    cout << "quit" << endl;
    cout << "q" << endl;
}

vector<string> parseArguments(const string &arg)
{
    vector<string> result;
    char seperator = ' ';
    string::size_type prev_pos = 0, pos = 0;

    while((pos = arg.find(seperator, pos)) != std::string::npos)
    {
        std::string substring( arg.substr(prev_pos, pos-prev_pos) );
        result.push_back(substring);
        prev_pos = ++pos;
    }

    result.push_back(arg.substr(prev_pos, pos-prev_pos));

    return result;
}

void loadImage(map<string, Image> &images, const string &key, const string &path)
{
    Image image;
    try
    {
        image.read(path);
        images.insert({key, image});

        cout << "Loaded image: " << key << " " << path << endl;
    }
    catch( Exception &error_ )
    {
        cout << "ERROR: Caught exception: " << error_.what() << endl;
    }
}

void saveImage(Image &image, const string path)
{
    try
    {
        image.write(path);
        cout << "Image saved: " << path << endl;
    }
    catch( Exception &error_ )
    {
        cout << "ERROR: Caught exception: " << error_.what() << endl;
    }
}

void setBlurImage(map<string, Image> &images, const string &keyFrom, const string &keyTo, double size)
{
    if(!images.count(keyFrom))
    {
        cout << "ERROR: Image \"" << keyFrom << "\" is not loaded!" << endl;
        return;
    }

    try
    {
        Image blurImage = images[keyFrom];
        blurImage.blur(size, 10.0);
        images.insert({keyTo, blurImage});
        cout << "Image blur applied: " << keyTo << endl;
    }
    catch( Exception &error_ )
    {
        cout << "ERROR: Caught exception: " << error_.what() << endl;
    }
}

void setResizeImage(map<string, Image> &images, const string &keyFrom, const string &keyTo, int width, int height)
{
    if(!images.count(keyFrom))
    {
        cout << "ERROR: Image \"" << keyFrom << "\" is not loaded!" << endl;
        return;
    }

    try
    {
        Image resizeImage = images[keyFrom];
        resizeImage.resize(Geometry(static_cast<size_t>(width), static_cast<size_t>(height)));
        images.insert({keyTo, resizeImage});
        cout << "Image resize applied: " << keyTo << endl;
    }
    catch( Exception &error_ )
    {
        cout << "ERROR: Caught exception: " << error_.what() << endl;
    }
}

int main(int argc, char *argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    cout << "This is the ImageMagick test app" << endl;

    InitializeMagick(*argv);
    map<string, Image> imagesMap;

    while(true)
    {
        string input;
        cout << ">";
        getline(cin >> ws, input);

        vector<string> arguments = parseArguments(input);

        if(arguments.size() > 0)
        {
            string command = arguments[0];

            if(command == "q" ||
               command == "exit" ||
               command == "quit")
            {
                break;
            }
            else if(command == "ld" ||
                    command == "load")
            {
                if(arguments.size() != 3)
                    cout << "ERROR: Wrong arguments!" << endl;
                else loadImage(imagesMap, arguments[1], arguments[2]);
            }
            else if(command == "s" ||
                    command == "store")
            {
                if(arguments.size() != 3)
                    cout << "ERROR: Wrong arguments!" << endl;
                else
                {
                    string key = arguments[1];
                    string path = arguments[2];

                    if(imagesMap.count(key))
                        saveImage(imagesMap[key], path);
                    else cout << "ERROR: Image \"" << key << "\" is not loaded!" << endl;
                }
            }
            else if(command == "blur")
            {
                if(arguments.size() != 4)
                    cout << "ERROR: Wrong arguments!" << endl;
                else
                {
                    string keyFrom = arguments[1];
                    string keyTo = arguments[2];
                    string strSize = arguments[3];
                    double size = stod(strSize);
                    setBlurImage(imagesMap, keyFrom, keyTo, size);
                }
            }
            else if(command == "resize")
            {
                if(arguments.size() != 5)
                    cout << "ERROR: Wrong arguments!" << endl;
                else
                {
                    string keyFrom = arguments[1];
                    string keyTo = arguments[2];
                    string strWidth = arguments[3];
                    string strHeight = arguments[4];
                    int width = stoi(strWidth);
                    int height = stoi(strHeight);
                    setResizeImage(imagesMap, keyFrom, keyTo, width, height);
                }
            }
            else if(command == "help" || command == "h")
            {
                showHelp();
            }
        }
    }

    return 0;
}
