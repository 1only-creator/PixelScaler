#!/bin/bash
# Setup script for Pixel 10 Pro / Termux
pkg update && pkg upgrade -y
pkg install python clang cmake ninja ffmpeg libopencl-vendor-driver opencv -y

python -m venv venv
source venv/bin/activate

pip install --upgrade pip
pip install numpy tqdm opencv-python
echo "Installation complete. Run 'source venv/bin/activate' before usage."