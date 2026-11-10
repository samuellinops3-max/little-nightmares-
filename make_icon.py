from PIL import Image, ImageDraw

# Cria o icone 320x176 do PS3
img = Image.new("RGB", (320, 176), (10, 10, 30))
draw = ImageDraw.Draw(img)
# fundo com cara de Little Nightmares
draw.rectangle([0, 0, 320, 176], fill=(15, 15, 35))
draw.ellipse([140, 40, 180, 90], fill=(255, 220, 100)) # lampada
draw.rectangle([120, 110, 200, 160], fill=(40, 40, 60)) # Six
draw.text((70, 145), "Little Nightmares", fill=(255,255,255))
img.save("ICON0.PNG")
print("ICON0.PNG criado!")