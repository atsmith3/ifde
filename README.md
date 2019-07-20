# Image Feature Depth Extraction (IFDE)

Project for the Qualcomm Hackmobile Intern event. The project takes in a set of images and can extract the depth of features in the scene using only a camera. The aperture is set very low to have a small depth of field. This makes any edge/feature not within the slim focal plane out of focus. By sweeping the focus point from near to far and taking a sequence of photos will categorize the features in the photo to a specific focal length. To detect the features present at a specific depth an edge detection is run on all the images in the input set. Then the resulting convolved image is passed through a simple threshold detect to eliminate noise. Lastly the depth of each pixel is recorded based on its mean depth in the processed image set.

The data is then visualized in Open3D (Point Cloud) and MatPlotLib (Heat Map).

## Build
Requirements (C++):
* [clang](https://clang.llvm.org/) - Compiler
* [boost](https://www.boost.org/) - Options & Arguments
* [libpng](http://www.libpng.org/pub/png/libpng.html) - Image Processing

To Build Convolution Engine:
```
cd src && make clean && make -j && cd ..
```

To Build Testbench:
```
cd src && make clean && make test -j && cd ..
```

Requirements (Python):
* [Python3](https://www.python.org/)
* [MatPlotLib](https://matplotlib.org/) - Heat Map
* [Open3D](http://www.open3d.org/) - Point Cloud Visualization

## Run
To run:
```
./run.sh
```

## Authors

* **Andrew Smith** - *Team Lead & Convolution Engine* - [atsmith3](https://github.com/atsmith3)
* **Gabrielle Campos** - *Point Cloud Visualization* - [gcampos1](https://github.com/gcampos1)
* **Anjelique Melendez** - *Convolution Engine* - [anjmelendez](https://github.com/anjmelendez)
* **Ishaaq Ibrahim** - *Heat Map* - [ishaaqibrahim](https://github.com/ishaaqibrahim)

See also the list of [contributors](https://github.com/atsmith3/dofe/graphs/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
