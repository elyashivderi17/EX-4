/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;
#include "calculate.hpp"
#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"},c5678{"5678"},c7777{"7777"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"},g5678{"5678"},g7777{"7777"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBull_And_Cows("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBull_And_Cows("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

///// My_test ////////////
		testcase.setname("My_test")
	// test one - general
		.CHECK_OUTPUT(calculateBull_And_Cows("13131","62628"), "0,0")      // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBull_And_Cows("15531","22232"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBull_And_Cows("12345","54321"), "1,4")      // 1 bull, 4 pgia
		.CHECK_OUTPUT(calculateBull_And_Cows("12345","12348"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBull_And_Cows("78967","71237"), "2,0")      // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBull_And_Cows("12345","98765"), "1,0")      // 1 bull, 0 pgia
    .CHECK_OUTPUT(calculateBull_And_Cows("12345","12345"), "5,0")      // 5 bull, 0 pgia
    .CHECK_OUTPUT(calculateBull_And_Cows("54321","13245"), "0,5")      // 0 bull, 5 pgia

		//Second test - String length is different
		.CHECK_OUTPUT(calculateBull_And_Cows("44444","1234"), "1,0")       // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBull_And_Cows("12345","123"), "3,0")        // 3 bull, 0 pgia
    .CHECK_OUTPUT(calculateBull_And_Cows("35790","35"), "2,0")         // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBull_And_Cows("12345","5"), "0,1")          // 0 bull, 1 pgia

    //test Third - Not a number
    .CHECK_OUTPUT(calculateBull_And_Cows("12345","dfghj"), "0,0")      // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBull_And_Cows("12345","*****"), "0,0")      // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBull_And_Cows("12345","1^&*4"), "1,1")      // 1 bull, 1 pgia

		// Fourth test - String lengths 
	  .CHECK_OUTPUT(calculateBull_And_Cows("1","1"), "1,0")              // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBull_And_Cows("12","12"), "2,0")            // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBull_And_Cows("123","132"), "1,2")          // 1 bull, 2 pgia
		.CHECK_OUTPUT(calculateBull_And_Cows("1235","1325"), "2,2")        // 2 bull, 2 pgia

		// The length of the guess is greater than the length of the answer
		.CHECK_OUTPUT(calculateBull_And_Cows("123","12345"), "3,0")        // 3 bull, 0 pgia
		.CHECK_OUTPUT(calculateBull_And_Cows("1","345"), "0,0")            // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBull_And_Cows("44","3445"), "1,0")          // 1 bull, 0 pgia
;
		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)     // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		
		////////////////// My_test //////////////////////////
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 0)      // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c5678, g5678, 4, 100), 1)       // guesser wins in one turn.
		.CHECK_EQUAL(play(c5678, g7777, 4, 100), 101)     // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c7777, g7777, 4, 100), 1)       // guesser wins in one turn.
		.CHECK_EQUAL(play(c5678, g12345, 4, 100), 101)    // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c9999, g9999, 4, 100), 1)       // guesser wins in one turn.
		.CHECK_EQUAL(play(c12345, g5678, 4, 100), 0)      // chooser loses technically by choosing an illegal number (too long).
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=10, true);  // smarty should always win in at most 10 turns!

		}

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}

