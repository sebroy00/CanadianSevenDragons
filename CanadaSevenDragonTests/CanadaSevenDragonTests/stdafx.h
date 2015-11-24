// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

// Headers for CppUnitTest
#include "CppUnitTest.h"

// TODO: reference additional headers your program requires here
#include "../../../CanadianSevenDragons/VisualStudio_files/CanadianSevenDragons/AnimalCardFactory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TestClassName)
{
public:
	TEST_METHOD(TestMethodName)
	{
		// Run a function under test here.
		Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
	}
}
