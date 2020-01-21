# RT
A 3D ray-tracing program that renders computer generated images.

A 42 project done with Jeongmo Bae (@jebae), Samuel Boniface (@sabonifa), and Alexandru Moraru (@almoraru).

## INSTALLATION

# Web Interface
- Install Node.js

# RT Program
Run make inside the repo.
```
$ make path/to/repo
```
## LAUNCHING 
# RT Program
- The program takes an xml scene file as the input, you can create your own or use the already created scenes.
- Modified files modified and saved are rerendered due to hot-loading implemented in project.
```
$ ./rtv1 scenes/file_name.xml
```

# Web Interface
```
$ node path/to/interface/index.js
```

## RT FEATURES
- 11 Objects: cone, cylinder, plane, sphere, box, ellipsoid, ring, parabaloid, pyramid, rectangle, and triangle.
- Shadows
- Multispot Lighting
- Spherical and directional lighting
- Ambient lighting
- Filters: sterioscope, sepia, and black & white
- Translation and rotation (camera and shapes)
- XML parsing and debugging
- Refraction, reflection, and transparency
- Texture mapping and bumping
- Rotation and translation
- Multithread computation
- Hot-loading
- Color

## WEB INTERFACE FETURES
- Modify camera
- Add a new object
- Live update for chosen file
