#include <iostream>
#include "mymesh.h"
#include <wrap/io_trimesh/export_obj.h>
#include <wrap/io_trimesh/export_stl.h>
#include <wrap/io_trimesh/import_stl.h>
#include <wrap/io_trimesh/import_obj.h>
#include "QuickHull.h"
using namespace vcg;
int main()
{
	CMeshO inputMesh;
	CMeshO outputMesh;
	int mark = 0;
	std::string input_name = "D:\\data\\ConvexHull\\input.stl";
	std::string output_name = "D:\\data\\ConvexHull\\output.obj";
	vcg::tri::io::ImporterSTL<CMeshO>::OpenBinary(inputMesh, input_name.c_str(), mark);
	QuickHull ch(inputMesh);
	ch.apply();
	outputMesh = ch.getMesh();
	vcg::tri::io::ExporterOBJ<CMeshO>::Save(outputMesh, output_name.c_str(),mark);
}