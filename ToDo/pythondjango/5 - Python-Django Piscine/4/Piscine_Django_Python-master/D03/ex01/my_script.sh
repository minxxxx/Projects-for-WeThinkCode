#!/bin/sh

pip3 --version
pip3 install -t local_lib --upgrade git+https://github.com/jaraco/path.py.git > my_install.log && python3 my_program.py

