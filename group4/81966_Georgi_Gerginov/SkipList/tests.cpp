#include "skip/skipList.h"
#include "../../../shared/specs/specHelper.h"

TEST_CASE("SkipList") {
	SUBCASE("push methods") {
		SUBCASE("push_back") {
			SkipList test;

			CHECK(test.length() == 0);

			test.push_back(1);
			CHECK(test.length() == 1);
			CHECK(test.start() -> value == 1);
			CHECK(test.end() -> value == 1);
			CHECK(test.start() == test.end());
			CHECK(!test.start() -> next);
			CHECK(!test.end() -> next);

			test.push_back(2);
			CHECK(test.length() == 2);
			CHECK(test.start() -> value == 1);
			CHECK(test.end() -> value == 2);
			CHECK(test.start() != test.end());
			CHECK(test.start() -> next);
			CHECK(!test.end() -> next);
		}
		
		SUBCASE("push_front") {
			SkipList test;

			CHECK(test.length() == 0);

			test.push_front(1);
			CHECK(test.length() == 1);
			CHECK(test.start() -> value == 1);
			CHECK(test.end() -> value == 1);
			CHECK(test.start() == test.end());
			CHECK(!test.start() -> next);
			CHECK(!test.end() -> next);

			test.push_front(2);
			CHECK(test.length() == 2);
			CHECK(test.start() -> value == 2);
			CHECK(test.end() -> value == 1);
			CHECK(test.start() != test.end());
			CHECK(test.start() -> next);
			CHECK(!test.end() -> next);
		}

		SUBCASE("push") {
			SkipList test;

			CHECK(test.length() == 0);

			test.push(1);
			CHECK(test.length() == 1);
			CHECK(test.start() -> value == 1);
			CHECK(test.end() -> value == 1);
			CHECK(test.start() == test.end());
			CHECK(!test.start() -> next);
			CHECK(!test.end() -> next);

			test.push(2);
			CHECK(test.length() == 2);
			CHECK(test.start() -> value == 1);
			CHECK(test.end() -> value == 2);
			CHECK(test.start() != test.end());
			CHECK(test.start() -> next);
			CHECK(!test.end() -> next);

			test.push(4);
			CHECK(test.length() == 3);
			CHECK(test.start() -> value == 1);
			CHECK(test.end() -> value == 4);
			CHECK(test.start() != test.end());
			CHECK(test.start() -> next);
			CHECK(!test.end() -> next);

			test.push(3);
			CHECK(test.length() == 4);
			CHECK(test.start() -> value == 1);
			CHECK(test.end() -> value == 4);
			CHECK(test.start() != test.end());
			CHECK(test.start() -> next);
			CHECK(!test.end() -> next);

			test.push(5);
			test.push(6);
			test.push(7);
			test.push(8);
			test.push(9);

			CHECK(test.start() -> skip);
			CHECK(test.start() -> skip -> value == 4);
			CHECK(test.start() -> skip -> skip -> value == 7);
			CHECK(test.start() -> skip -> skip -> skip -> value == 9);
			CHECK(!test.end() -> skip);
		}
	}

	SUBCASE("pop methods") {
		SUBCASE("pop_back") {
			SkipList test{1, 2};

			CHECK(test.length() == 2);
			CHECK(test.start() -> value == 1);
			CHECK(test.end() -> value == 2);
			CHECK(test.start() != test.end());
			CHECK(test.start() -> next);
			CHECK(!test.end() -> next);
			
			test.pop_back();
			CHECK(test.length() == 1);
			CHECK(test.start() -> value == 1);
			CHECK(test.end() -> value == 1);
			CHECK(test.start() == test.end());
			CHECK(!test.start() -> next);
			CHECK(!test.end() -> next);

			test.pop_back();
			CHECK(test.length() == 0);
			CHECK(test.start() == test.end());
			CHECK(!test.start());
			CHECK(!test.end());
		}
		
		SUBCASE("pop_front") {
			SkipList test{1, 2};

			CHECK(test.length() == 2);
			CHECK(test.start() -> value == 1);
			CHECK(test.end() -> value == 2);
			CHECK(test.start() != test.end());
			CHECK(test.start() -> next);
			CHECK(!test.end() -> next);
			
			test.pop_front();
			CHECK(test.length() == 1);
			CHECK(test.start() -> value == 2);
			CHECK(test.end() -> value == 2);
			CHECK(test.start() == test.end());
			CHECK(!test.start() -> next);
			CHECK(!test.end() -> next);

			test.pop_front();
			CHECK(test.length() == 0);
			CHECK(test.start() == test.end());
			CHECK(!test.start());
			CHECK(!test.end());
		}
	}
}
