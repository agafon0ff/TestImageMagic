# SimpleRemoteDesktop
**TestImageMagick - Test application using ImageMagic libraries.**

**Install ImageMagic libraries steps:**
1. Load sources:<br/>
wget https://www.imagemagick.org/download/ImageMagick.tar.gz

2. Untar:<br/>
tar xf ImageMagick.tar.gz
cd ImageMagick-7*

3. Install depends:<br/>
sudo apt-get install libpng-dev libjpeg-dev -y

4. Configure libraries:<br/>
./configure --enable-shared

5. Install:<br/>
make
sudo make install
sudo ldconfig /usr/local/lib



