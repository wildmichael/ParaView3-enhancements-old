This directory contains a subset of the libogg-1.1.4 and libtheora-1.1alpha2
libraries and some custom changes. The reason to choose the alpha version of
the latter is that it features much better assembly code for x86 architectures,
encoding is faster and shows no instabilities for our purposes.

We only include enough of the distribution to provide the functionalities
required. Both libraries are compiled into the single vtkoggtheora library.

We would like to thank Xiph.org for distributing these libraries.
http://www.xiph.org

Added Files
-----------

CMakeLists.txt
  -Support building with CMake.

vtkoggtheora.rc
  -For MS Windows only: provide a version resource in a dll build so that
   when you look at the dll file in Windows explorer, it will show you the
   version in the "Version" tab of the file's properties view.

vtkoggtheora.def
vtkoggtheora.exp
vtkoggtheora.vscript
  -For MS Windows, Mac OS X and Linux respectively: used to explicitly list the
   exports from dll builds. Only the functions actually used in
   vtkOggTheoraWriter are exported.

vtk_oggtheora_mangle.h
  -Mangles symbols exported from the ogg/theora libraries for use by VTK.

Changed Files
-------------
You can search the code for "KITWARE_OGGTHEORA_CHANGE" to find modifications
vs the original ogg/theora code.
