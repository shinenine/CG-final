#define _CRT_SECURE_NO_WARNINGS
#include "raytracing.h"
#include "showpicture.h"

//Create a sign including 5 spheres and 1 light (which is also a sphere), then render it.
int main()
{
	std::vector<Solid*> solids;	Cube wall1 = Cube(Vec_3f(0, 0, 0), 2000, 0.1f, 2000, Vec_3f(0.40, 0.40, 0.20), 0.0f, 0.0f);
	solids.push_back(&wall1);

	//argument: position, radius, surfaceColor, reflectivity, transparency, emissionColor

	//Objects
	Sphere tmp1 = Sphere(Vec_3f(0.0, 0, 0), 4, Vec_3f(1.00, 0.00, 0.00), 1, 0.5);
	Cube tmp2 = Cube(Vec_3f(1, -4, 5), 2, 2, 2, Vec_3f(1.00, 1.00, 0.00), 0.0, 0.0);
	Sphere tmp3 = Sphere(Vec_3f(5.0, -1, 5), 2, Vec_3f(0.00, 0.6549f, 0.4824f), 0, 0.0);
	Sphere tmp4 = Sphere(Vec_3f(5.0, 0, -5), 3, Vec_3f(0.00, 0.00, 1.00), 1, 0.0);
	Sphere tmp5 = Sphere(Vec_3f(-5.5, 0, 5), 3, Vec_3f(0.00, 1.00, 0.00), 1, 0.0);
	solids.push_back(&tmp1);
	//solids.push_back(&tmp2);
	solids.push_back(&tmp3);
	// solids.push_back(&tmp4);
	solids.push_back(&tmp5);

	//Ground
	Cube ground = Cube(Vec_3f(-1000, -4, -1000), 2000, 0.1f, 2000, Vec_3f(0.40, 0.20, 0.20), 0.0f, 0.0f);
	solids.push_back(&ground);

	
	//Light
	Sphere tmp7 = Sphere(Vec_3f(-20.0f, 20, 10), 3, Vec_3f(0.0, 0.0, 0.0), 0, 0.0, Vec_3f(2));
	solids.push_back(&tmp7);

	//下面是生成一张图片并显示的代码。
	//若未安装opencv，则删除showpicture及其相关代码
	char* file = (char*)"./1.ppm";
	render(file, solids, Vec_3f(0, 0, 15));
	showpicture(file);
	/*
	//下面是生成光源移动视频的代码，共200帧图片
	char files[200][20];
	for (int i = 0;i < 200; i++)
	{
		solids.pop_back();
		Sphere tmp8 = Sphere(Vec_3f(-20.0f * cos(0.9f * i / 180 * M_PI), 20, 20.0f * sin(0.9f * i / 180 * M_PI)), 3, Vec_3f(0.0, 0.0, 0.0), 0, 0.0, Vec_3f(2));
		solids.push_back(&tmp8);
		sprintf(files[i], "./lightfiles/%d.ppm", i);
		render(files[i], solids, Vec_3f(0, 0, 15));
	}

	//下面是生成视角移动视频的代码，共300帧图片
	char files2[300][20];
	for (int i = 0; i < 100; i++)
	{
		sprintf(files2[i], "./files/%d.ppm", i);
		render(files2[i], solids, Vec_3f(0, 0, 10.0f + 0.3f * i));
	}
	for (int i = 0; i < 100; i++)
	{
		sprintf(files2[i + 100], "./files/%d.ppm", i + 100);
		render(files2[i + 100], solids, Vec_3f(0, 40 * sin(0.9f * i / 180 * M_PI), 40 * cos(0.9f * i / 180 * M_PI)), 0.9f * i);
	}
	for (int i = 0; i < 100; i++)
	{
		sprintf(files2[i + 200], "./files/%d.ppm", i + 200);
		render(files2[i + 200], solids, Vec_3f(0, 40.0f - 0.3f * i, 0), 90.0f);
	}
	*/


	return 0;
}