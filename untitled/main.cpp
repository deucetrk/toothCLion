// STD
#include <iostream>
#include "include/header/Matrix4.h"
#include "include/header/Vec3.h"
#include "include/header/SphereTree.h"
#include "include/header/Matrix4.h"
#include "include/header/SphereNode.h"
#include "include/header/Bankhelper.h"
#include "include/header/test.h"
#include <string>
// ROS
// SWI prolog
#define PL_SAFE_ARG_MACROS
//#include <SWI-cpp.h>

int main ()
{
std::string str;
int PL_A1 =300;
std::cout << "Your input =  " << toString(PL_A1) << std::endl;
std::string t1 = "./../input/";
std::string t3 = ".log";
std::string t4 = t1+toString(PL_A1) +t3;

//std::cout << "Your t1 =  " << t1 << std::endl;

//std::cout << "Your t3 =  " << t3 << std::endl;
//std::cout << "Your t4 =  " << t4 << std::endl;


// register tooth

auto M = pd::Matrix4<float>::IDENTITY();
/*
	//aom try
	int maxNum = PL_A1;
	 int p1=0;
    int p2=0;
    int start = 0;
    while(maxNum>start)
    {

        p1=start;
        p2=start+1;
        start++;
	std::string F1 =  "./src/knowrob/knowrob_bank/src/input/";
	std::string F2 = ".log";
	std::string F3 = F1+toString(p1)+F2;


	std::string L1 =  "./src/knowrob/knowrob_bank/src/input/";
	std::string L2 = ".log";
	std::string L3 = F1+toString(p2)+F2;

	test::registerIdealEnvIST(F3,1,M,1,L3,PL_A1);

        //printf("P1 %d || P2 %d\n",p1,p2);

	std::cout << "Your F3 =  " << F3 << std::endl;
	std::cout << "Your L3 =  " << L3 << std::endl;
	std::cout << "Your maxNum =  " << maxNum << std::endl;
	std::cout << "Your start =  " << start << std::endl;


}

*/
std::string F1 =  "./../input/0.log";
test::registerIdealEnvIST(F1,1,M,1,t4,PL_A1);



// Dimentional Setting
Vec3<float> m_min( -90, -90, -90);
Vec3<float> m_max( 90, 90, 90);

Vec3<float> m_wd( m_max - m_min );
Vec3<float> m_d(  100,100,100 );
Vec3<float> m_df( m_d.x, m_d.y, m_d.z );
Vec3<float> m_cellDim( m_wd/m_df );
float *m_scalarFieldRaw = new float[(int)(m_d.x*m_d.y*m_d.z)];
Vec3<float> max(m_df);
Vec3<float> min( 0, 0, 0);


// Compute ScalarField
test::cpukern_scalarField(m_min,m_max,m_wd,
        m_cellDim, min, max, m_df,
        m_scalarFieldRaw, true, test::g_idealEnvLeafCount, test::g_idealEnvLeafX,
test::g_idealEnvLeafY, test::g_idealEnvLeafZ, test::g_idealEnvLeafR,true);

int n = sizeof(m_scalarFieldRaw) / sizeof(m_scalarFieldRaw);
std::reverse(m_scalarFieldRaw,m_scalarFieldRaw+n);

test::MarchCubes(m_scalarFieldRaw,m_df,m_wd,m_wd);

test::writeFile(test::m_gridToTriangles);

test::convertObjtoDea();



return 0;


};






