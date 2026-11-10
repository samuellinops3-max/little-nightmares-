name: Build Little Nightmares PS3
on:
  push:
    branches: [ main ]
jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
      - name: Build
        run: |
          pip install Pillow
          gcc main.c -o EBOOT.BIN
          python3 make_sfo.py
          python3 make_icon.py
          python3 make_pic.py
          mkdir -p USRDIR
          cp EBOOT.BIN USRDIR/EBOOT.BIN
          cp PARAM.SFO USRDIR/PARAM.SFO
          python3 make_pkg.py
          ls -lh
      - uses: actions/upload-artifact@v4
        with:
          name: Little-Nightmares-PS3-Final
          path: little_nightmares.pkg