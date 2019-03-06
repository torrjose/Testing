#include "pch.h"
#include "gtest/gtest.h"
#include "./oxygine-framework-with-sdl/oxygine-framework/oxygine/src/oxygine-include.h"
#include "./oxygine-framework-with-sdl/oxygine-framework/oxygine/src/oxygine/math/Rect.h"


namespace oxygine
{
	TEST(RectTest, Works)
	{			// x,y,w,h
		oxygine::Rect A = oxygine::Rect(1, 1, 1, 1);
		oxygine::Rect B = oxygine::Rect(0, 0, 2, 3);

		ASSERT_EQ(A.getY(), 1);
		ASSERT_EQ(A.getX(), 1);

		ASSERT_TRUE(A.isIntersecting(B));

		B.moveTop(3);

		ASSERT_FALSE(A.isIntersecting(B));

		A = B;

		ASSERT_EQ(A, B);

		A=A * 2; 

		B = B * 8;

		B = B / 2;

		ASSERT_NE(A, B);

		B.setSize(0, 0);

		ASSERT_TRUE(B.isEmpty());

		B = A;

		ASSERT_EQ(A.getLeft(), B.getLeft());

		ASSERT_EQ(A.getWidth(), B.getWidth());

		ASSERT_EQ(A.getRight(), B.getRight());

		A.set(0, 0, 2, 2);
		
		B.setPosition(0, 0);

		B.setSize(2, 2);

		ASSERT_EQ(A.getCenter(), B.getCenter());

		A.setPosition(3, 3);

		B.setSize(1, 1);

		ASSERT_NE(A, B);
	}
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}