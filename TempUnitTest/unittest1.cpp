#include "stdafx.h"
#include "CppUnitTest.h"

#include "C:\Users\ethan\Documents\Visual Studio 2017\Projects\ConsoleApplication1\ConsoleApplication1\temp.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TempUnitTest {	

	TEST_CLASS(UnitTest1) {
	public:		
		TEST_METHOD(TestMethod1) {

			ListNode* headA = new ListNode(1);
			ListNode* ptr = headA;
			ptr->next = new ListNode(2);

			ptr = ptr->next;
			ptr->next = new ListNode(3);

			ptr = ptr->next;
			ptr->next = new ListNode(4);
			ListNode* intersect = ptr;
			const ListNode* intersection = intersect;

			ptr = ptr->next;
			ptr->next = new ListNode(5);

			//--

			ListNode* headB = new ListNode(10);
			ptr = headB;
			ptr->next = new ListNode(20);

			ptr = ptr->next;
			ptr->next = new ListNode(30);

			ptr = ptr->next;
			ptr->next = new ListNode(40);

			ptr = ptr->next;
			ptr->next = intersect;

			//--

			temp tmp;
			const ListNode* res = tmp.getIntersectionNode(headA, headB);

			if (res != intersection)
				throw exception("NOT EQUAL");

		};

	};
}