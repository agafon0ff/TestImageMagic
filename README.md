# SimpleRemoteDesktop
**TestImageMagick - Test application using ImageMagic libraries.**

**Install ImageMagic libraries steps:**
1. Load sources:<br/>
wget https://www.imagemagick.org/download/ImageMagick.tar.gz<br/>

2. Untar:<br/>
tar xf ImageMagick.tar.gz<br/>
cd ImageMagick-7*<br/>

3. Install depends:<br/>
sudo apt-get install libpng-dev libjpeg-dev -y<br/>

4. Configure libraries:<br/>
./configure --enable-shared<br/>

5. Install:<br/>
make<br/>
sudo make install<br/>
sudo ldconfig /usr/local/lib<br/>



