#include "pch.h"
#include "CppUnitTest.h"
#include "SpatialHash.h"
#include "Critter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<>
std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<roundedCoordinate>(const roundedCoordinate& c)
{
	return L"(" + std::to_wstring(c.x) + L", " + std::to_wstring(c.y) + L")";
}
namespace CDDSOptimiseTests
{
	TEST_CLASS(CDDSOptimiseTests)
	{
	public:
		
		TEST_METHOD(SnapPos_ReturnsCorrectCell)
		{
			
			// Arrange
			Vector2 pos = { 25.0f, 25.0f };

			// Act
			roundedCoordinate result = SnapPos(pos, 12.0f);

			// Assert
			Assert::AreEqual(2, result.x);
			Assert::AreEqual(2, result.y);
			
		}
		TEST_METHOD(SnapPos_RadiusZero)
		{
			Vector2 pos = { 1.0f, 1.0f };
			roundedCoordinate result = SnapPos(pos, 0.0f);
			Assert::AreEqual(0, result.x);
			Assert::AreEqual(0, result.y);
		}
		TEST_METHOD(SnapPos_Negative)
		{
			Vector2 pos = { -1.0f, -1.0f };
			roundedCoordinate result = SnapPos(pos, 10.0f);
			Assert::AreEqual(-1, result.x);
			Assert::AreEqual(-1, result.y);
		}
		TEST_METHOD(SnapPos_Snap)
		{
			Vector2 pos0 = { 1.0f, 1.0f };
			Vector2 pos1 = { 1.5f, 1.5f };
			roundedCoordinate result = SnapPos(pos0, 10.0f);
			roundedCoordinate other = SnapPos(pos1, 10.0f);
			Assert::AreEqual(result.x, other.x);
			Assert::AreEqual(result.y, other.y);
		}
		TEST_METHOD(RC_equal)
		{
			roundedCoordinate x = { 1,1 };
			roundedCoordinate y = { 1,1 };
			Assert::IsTrue(x == y);
		}

	};
}
