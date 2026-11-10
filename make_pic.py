from PIL import Image, ImageDraw
img = Image.new("RGB", (1920, 1080), (10, 10, 25))
draw = ImageDraw.Draw(img)
draw.rectangle([0, 0, 1920, 1080], fill=(12, 12, 30))
draw.ellipse([900, 200, 1020, 400], fill=(255, 210, 80))
draw.text((750, 600), "Little Nightmares - Sombra", fill=(255,255,255))
img.save("PIC1.PNG")
print("PIC1.PNG criado!")