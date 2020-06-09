# SimpleRemoteDesktop
**TestImageMagick - Test application using ImageMagic libraries.**

**Install ImageMagic libraries steps:**
1. Load sources:
wget https://www.imagemagick.org/download/ImageMagick.tar.gz

2. Untar:
tar xf ImageMagick.tar.gz
cd ImageMagick-7*

3. Install depends:
sudo apt-get install libpng-dev libjpeg-dev -y

4. Configure libraries:
./configure --enable-shared

5. Install:
make
sudo make install
sudo ldconfig /usr/local/lib



