import os
print("Juntando PKG final...")
files = ["USRDIR/EBOOT.BIN", "USRDIR/PARAM.SFO", "ICON0.PNG", "PIC1.PNG"]
pkg = b"PKG\x00"
for f in files:
    if os.path.exists(f):
        data = open(f, "rb").read()
        pkg += data
        print(f, "OK", len(data))
    else:
        print(f, "FALTOU!")
open("little_nightmares.pkg", "wb").write(pkg)
print("PKG pronto!", os.path.getsize("little_nightmares.pkg"))