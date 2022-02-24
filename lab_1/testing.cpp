#include "testing.h"

#define PARALLELOGRAMM 1
#define RECTANGLE 2
#define SQUARE 3
#define RHOMB 4



void Test() {
	cerr << "Тестирование класса Rectangle\n";
	{
		Rectangle r(4, 2, 2., 1.);
		Assert(r.GetParams(), vector<float>{ 4, 2, 2, 1, 90 }, "1");
		Assert(r.IsBoarder({ 0,1 }), true, "2");
		Assert(r.IsBoarder({ 0,3 }), false, "3");
		Assert(r.IsBoarder({ 1,1 }), false, "4");
		Assert(r.IsBoarder({ 4,2 }), true, "5");
		Assert(r.IsBoarder({ 3,3 }), false, "6");
		Assert(r.IsCrossesAbscissa(), true, "7");
		Assert(r.IsCrossesOrdinate(), true, "8");
	}
	{
		Rectangle r(4, 2, 15., -4.);
		r.SetNewCenter(2, 1);
		Assert(r.GetParams(), vector<float>{ 4, 2, 2, 1, 90 }, "9");
		Assert(r.IsBoarder({ 0,1 }), true, "10");
		Assert(r.IsBoarder({ 0,3 }), false, "11");
		Assert(r.IsBoarder({ 1,1 }), false, "12");
		Assert(r.IsBoarder({ 4,2 }), true, "13");
		Assert(r.IsBoarder({ 3,3 }), false, "14");
		Assert(r.IsCrossesAbscissa(), true, "15");
		Assert(r.IsCrossesOrdinate(), true, "16");
	}
	{
		Rectangle r(4, 2, 1, 0);
		Assert(r.GetParams(), vector<float>{ 4, 2, 1, 0, 90 }, "17");
		Assert(r.IsBoarder({ 0,1 }), true, "18");
		Assert(r.IsBoarder({ 0,3 }), false, "19");
		Assert(r.IsBoarder({ 1,1 }), true, "20");
		Assert(r.IsBoarder({ 3.006,1 }), false, "21");
		Assert(r.IsBoarder({ 3.005,1 }), true, "22");
		Assert(r.IsCrossesAbscissa(), true, "23");
		Assert(r.IsCrossesOrdinate(), true, "24");
	}
	{
		Rectangle r(4, 2, 6, -4);
		r.MoveCenter(-5, 4);
		Assert(r.GetParams(), vector<float>{ 4, 2, 1, 0, 90 }, "25");
		Assert(r.IsBoarder({ 0,1 }), true, "26");
		Assert(r.IsBoarder({ 0,3 }), false, "27");
		Assert(r.IsBoarder({ 1,1 }), true, "28");
		Assert(r.IsBoarder({ 3.006,1 }), false, "29");
		Assert(r.IsBoarder({ 3.005,1 }), true, "30");
		Assert(r.IsCrossesAbscissa(), true, "31");
		Assert(r.IsCrossesOrdinate(), true, "32");
	}
	{
		Rectangle r(4, 2, 7, 0);
		Assert(r.GetParams(), vector<float>{ 4, 2, 7, 0, 90 }, "33");
		Assert(r.IsCrossesAbscissa(), true, "34");
		Assert(r.IsCrossesOrdinate(), false, "35");
	}
	{
		Rectangle r(4, 2, 0, 4);
		Assert(r.GetParams(), vector<float>{ 4, 2, 0, 4, 90 }, "36");
		Assert(r.IsCrossesAbscissa(), false, "37");
		Assert(r.IsCrossesOrdinate(), true, "38");
	}
	{
		Rectangle r(4, 2, 0, 4);
		Assert(r.GetPerimetr(), 12, "39");
	}
	{
		Rectangle r(14, 3, -2, 3);
		Assert(r.GetPerimetr(), 34, "40");
	}
	cerr << "Тестирование класса Parallelogramm\n";
	{
		Parallelogramm r(7, (float)sqrt(20), 1.5, 3, (float)(atan(2) / PI * 180.));
		Assert(r.GetParams(), vector<float>{ 7, (float)(round(sqrt(20) * 1000) / 1000.), 1.5, 3, (float)(round(atan(2) / PI * 180. * 1000) / 1000.) }, "41");
		Assert(r.IsBoarder({ 0,1 }), true, "42");
		Assert(r.IsBoarder({ 5,2 }), false, "43");
		Assert(r.IsBoarder({ 1,0.995 }), true, "44");
		Assert(r.IsBoarder({ 1.5,3 }), false, "45");
		Assert(r.IsBoarder({ -2.5,2 }), true, "46");
		Assert(r.IsCrossesAbscissa(), false, "47");
		Assert(r.IsCrossesOrdinate(), true, "48");
	}
	{
		Parallelogramm r(7, (float)sqrt(20), 8, 2, (float)(atan(2) / PI * 180.));
		r.SetNewCenter(1.5, 3);
		Assert(r.GetParams(), vector<float>{ 7, (float)(round(sqrt(20) * 1000) / 1000.), 1.5, 3, (float)(round(atan(2) / PI * 180. * 1000) / 1000.) }, "41");
		Assert(r.IsBoarder({ 0,1 }), true, "49");
		Assert(r.IsBoarder({ 5,2 }), false, "50");
		Assert(r.IsBoarder({ 1,0.995 }), true, "51");
		Assert(r.IsBoarder({ 1.5,3 }), false, "52");
		Assert(r.IsBoarder({ -2.5,2 }), true, "53");
		Assert(r.IsCrossesAbscissa(), false, "54");
		Assert(r.IsCrossesOrdinate(), true, "55");
	}
	{
		Parallelogramm r(7, (float)sqrt(20), 8, 2, (float)(atan(2) / PI * 180.));
		r.MoveCenter(-6.5, 1);
		Assert(r.GetParams(), vector<float>{ 7, (float)(round(sqrt(20) * 1000) / 1000.), 1.5, 3, (float)(round(atan(2) / PI * 180. * 1000) / 1000.) }, "41");
		Assert(r.IsBoarder({ 0,1 }), true, "56");
		Assert(r.IsBoarder({ 5,2 }), false, "57");
		Assert(r.IsBoarder({ 1,0.995 }), true, "58");
		Assert(r.IsBoarder({ 1.5,3 }), false, "59");
		Assert(r.IsBoarder({ -2.5,2 }), true, "60");
		Assert(r.IsCrossesAbscissa(), false, "61");
		Assert(r.IsCrossesOrdinate(), true, "62");
	}
	cerr << "Тестирование класса Square\n";
	{
		Square r(3, 0.5, 3.5);
		Assert(r.GetParams(), vector<float>{ 3, 3, 0.5, 3.5, 90 }, "63");
		Assert(r.IsBoarder({ 0,1 }), false, "64");
		Assert(r.IsBoarder({ 2,2 }), true, "65");
		Assert(r.IsBoarder({ 2,1.995 }), true, "66");
		Assert(r.IsBoarder({ -0.5,5 }), true, "67");
		Assert(r.IsBoarder({ -2.5,2 }), false, "68");
		Assert(r.IsCrossesAbscissa(), false, "69");
		Assert(r.IsCrossesOrdinate(), true, "70");
	}
	{
		Square r(3, 7.5, 9.5);
		r.SetNewCenter(0.5, 3.5);
		Assert(r.GetParams(), vector<float>{ 3, 3, 0.5, 3.5, 90 }, "71");
		Assert(r.IsBoarder({ 0,1 }), false, "72");
		Assert(r.IsBoarder({ 2,2 }), true, "73");
		Assert(r.IsBoarder({ 2,1.995 }), true, "74");
		Assert(r.IsBoarder({ -0.5,5 }), true, "75");
		Assert(r.IsBoarder({ -2.5,2 }), false, "76");
		Assert(r.IsCrossesAbscissa(), false, "77");
		Assert(r.IsCrossesOrdinate(), true, "78");
	}
	{
		Square r(3, 7.5, 9.5);
		r.MoveCenter(-7, -6);
		Assert(r.GetParams(), vector<float>{ 3, 3, 0.5, 3.5, 90 }, "79");
		Assert(r.IsBoarder({ 0,1 }), false, "80");
		Assert(r.IsBoarder({ 2,2 }), true, "81");
		Assert(r.IsBoarder({ 2,1.995 }), true, "82");
		Assert(r.IsBoarder({ -0.5,5 }), true, "83");
		Assert(r.IsBoarder({ -2.5,2 }), false, "84");
		Assert(r.IsCrossesAbscissa(), false, "85");
		Assert(r.IsCrossesOrdinate(), true, "86");
	}
	cerr << "Тестирование класса Rhomb\n";
	{
		Rhomb r(4, 3, (float)sqrt(3), 60);
		Assert(r.GetParams(), vector<float>{ 4, 4, 3, (float)(round(sqrt(3) * 1000) / 1000.), 60 }, "87");
		Assert(r.IsBoarder({ 0,1 }), false, "88");
		Assert(r.IsBoarder({ 1,(float)sqrt(3) }), true, "89");
		Assert(r.IsBoarder({ 4,0 }), true, "90");
		Assert(r.IsBoarder({ 0,0 }), true, "91");
		Assert(r.IsBoarder({ 3, (float)(2 * sqrt(3)) }), true, "92");
		Assert(r.IsCrossesAbscissa(), true, "93");
		Assert(r.IsCrossesOrdinate(), true, "94");
	}
	{
		Rhomb r(4, 9, (float)sqrt(3) - 5, 60);
		r.SetNewCenter(3, (float)sqrt(3)); 
		Assert(r.GetParams(), vector<float>{ 4, 4, 3, (float)(round(sqrt(3) * 1000) / 1000.), 60 }, "95");
		Assert(r.IsBoarder({ 0,1 }), false, "96");
		Assert(r.IsBoarder({ 1,(float)sqrt(3) }), true, "97");
		Assert(r.IsBoarder({ 4,0 }), true, "98");
		Assert(r.IsBoarder({ 0,0 }), true, "99");
		Assert(r.IsBoarder({ 3, (float)(2 * sqrt(3)) }), true, "100");
		Assert(r.IsCrossesAbscissa(), true, "101");
		Assert(r.IsCrossesOrdinate(), true, "102");
	}
	{
		Rhomb r(4, 3, (float)sqrt(3), 60);
		r.SetNewCenter(8, 3 + (float)sqrt(3));
		r.BackToOriginal();
		Assert(r.GetParams(), vector<float>{ 4, 4, 3, (float)(round(sqrt(3) * 1000) / 1000.), 60 }, "103");
		Assert(r.IsBoarder({ 0,1 }), false, "104");
		Assert(r.IsBoarder({ 1,(float)sqrt(3) }), true, "105");
		Assert(r.IsBoarder({ 4,0 }), true, "106");
		Assert(r.IsBoarder({ 0,0 }), true, "107");
		Assert(r.IsBoarder({ 3, (float)(2 * sqrt(3)) }), true, "108");
		Assert(r.IsCrossesAbscissa(), true, "109");
		Assert(r.IsCrossesOrdinate(), true, "110");
	}
	{
		Rhomb r(4, 9, (float)sqrt(3) - 5, 60);
		r.MoveCenter(-6, 5);
		Assert(r.GetParams(), vector<float>{ 4, 4, 3, (float)(round(sqrt(3) * 1000) / 1000.), 60 }, "111");
		Assert(r.IsBoarder({ 0,1 }), false, "112");
		Assert(r.IsBoarder({ 1,(float)sqrt(3) }), true, "113");
		Assert(r.IsBoarder({ 4,0 }), true, "114");
		Assert(r.IsBoarder({ 0,0 }), true, "115");
		Assert(r.IsBoarder({ 3, (float)(2 * sqrt(3)) }), true, "116");
		Assert(r.IsCrossesAbscissa(), true, "117");
		Assert(r.IsCrossesOrdinate(), true, "118");
	}
	{
		Rhomb r(4, 3, (float)sqrt(3), 60);
		r.MoveCenter(-6, 5);
		r.BackToOriginal();
		Assert(r.GetParams(), vector<float>{ 4, 4, 3, (float)(round(sqrt(3) * 1000) / 1000.), 60 }, "119");
		Assert(r.IsBoarder({ 0,1 }), false, "120");
		Assert(r.IsBoarder({ 1,(float)sqrt(3) }), true, "121");
		Assert(r.IsBoarder({ 4,0 }), true, "122");
		Assert(r.IsBoarder({ 0,0 }), true, "123");
		Assert(r.IsBoarder({ 3, (float)(2 * sqrt(3)) }), true, "124");
		Assert(r.IsCrossesAbscissa(), true, "125");
		Assert(r.IsCrossesOrdinate(), true, "126");
	}
	cerr << "Тестирование Метода Rotate\n";
	{
		Rectangle r(6, 2, 2, -2);
		r.Rotate(90);
		Assert(r.IsCrossesAbscissa(), true, "127");
		Assert(r.IsCrossesOrdinate(), false, "128");
		Assert(r.IsBoarder({ 1,1 }), true, "129");
		Assert(r.IsBoarder({ 0,-1 }), false, "130");
		r.MoveCenter(-4, -2);
		Assert(r.IsCrossesAbscissa(), false, "131");
		Assert(r.IsCrossesOrdinate(), false, "132");
		Assert(r.IsBoarder({ -3,-1 }), true, "133");
		Assert(r.IsBoarder({ 1,-2 }), false, "134");
		r.BackToOriginal();
		Assert(r.IsCrossesAbscissa(), false, "135");
		Assert(r.IsCrossesOrdinate(), true, "136");
		Assert(r.IsBoarder({ 4,-1 }), true, "137");
		Assert(r.IsBoarder({ 1,0 }), false, "138");
	}
}