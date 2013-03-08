//
//  main.cpp
//  ProfilerMath
//
//  Created by enea  on 3/8/13.
//  Copyright (c) 2013 enea . All rights reserved.
//

#include <iostream>
#include "fdk/vec4f.h"
#include "fdk/mat44f.h"
#include "random_math.h"
#include "performance.h"
#include "fdk/ftl_common.h"
#include <time.h>

using namespace fdk;
using namespace performance;

int main(int argc, const char * argv[])
{
	F32 range = 10.f;
	Vec4f row0 = Vec4f(Randomf(range), Randomf(range), Randomf(range), Randomf(range));
	Vec4f row1 = Vec4f(Randomf(range), Randomf(range), Randomf(range), Randomf(range));
	Vec4f row2 = Vec4f(Randomf(range), Randomf(range), Randomf(range), Randomf(range));
	Vec4f row3 = Vec4f(Randomf(range), Randomf(range), Randomf(range), Randomf(range));
	Mat44f l = Mat44f(row0, row1, row2, row3);
	Mat44f outMat;
	Clock start = Start();
	Mat44fInvert(l, &outMat);
	Clock stop = Stop();
	F64 time = ExecutionTime(start, stop);
	printf("Execution time = %1.12lf milliseconds",1000 *  time);
	
	PerformanceTimer t;
	t.init();
	F64 timer;
	F64 elapsed = 0;
	I32 i;
	I32 count = 1000;
	for(i=0;i<count;i++) {
		//RandIntSetSeed((U32) time(NULL));
		// Return a random float between 0.0 and range, inclusive.
		F32 range = 10.f;
		Vec4f row0 = Vec4f(Randomf(range), Randomf(range), Randomf(range), Randomf(range));
		Vec4f row1 = Vec4f(Randomf(range), Randomf(range), Randomf(range), Randomf(range));
		Vec4f row2 = Vec4f(Randomf(range), Randomf(range), Randomf(range), Randomf(range));
		Vec4f row3 = Vec4f(Randomf(range), Randomf(range), Randomf(range), Randomf(range));
		Mat44f l = Mat44f(row0, row1, row2, row3);
		Mat44f outMat;
		t.tick();
		Mat44fInvert(l, &outMat);
		timer = t.tick();
		elapsed += timer;
		//printf("\n Timer: %e \n", timer);
		//printf("\n Elapsed: %e \n",elapsed);
	}
	
	printf("\n Time medium in milliseconds for cycle (TestPerformanceMathMat44fInvertSIMD) = %1.12lf \n",(elapsed)/count);
	printf("\n Time total in milliseconds for %d cycles (TestPerformanceMathMat44fInvertSIMD) = %1.12lf \n",count, elapsed);
	
	
	
    	return 0;
}

