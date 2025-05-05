/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Example "smoke test" (can be deleted)
TEST(GuesserTest, smoke_test)
{
  Guesser object("Secret");
  ASSERT_EQ( 1+1, 2 );
}

TEST(GuesserTest, Large_imput_test){
	Guesser object("this is a very long secret that shouldnt be able to be read");
	ASSERT_FALSE(object.match("this is a very long secret"));
}

TEST(GuesserTest, ideal_distance_cal){
	Guesser object("hello world");
	ASSERT_TRUE(object.match("hello world"));
}

TEST(GuesserTest, does_it_reset_to_three){
	Guesser object("password");
	ASSERT_TRUE(object.match("pasword"));
	ASSERT_EQ(object.remaining(), 3);
}

TEST(GuesserTest, Empty_Imput_Guess_and_secret){
	Guesser object("");
	ASSERT_TRUE(object.match(""));
	ASSERT_EQ(object.remaining(), 3);
}

TEST(GuesserTest, correct_match){
	Guesser object("secret");
	ASSERT_TRUE(object.match("secret"));
	ASSERT_EQ(object.remaining(), 3);
}

TEST(GuesserTest, incorrect_Match){
	Guesser object("password");
	ASSERT_FALSE(object.match("notpassword"));
	ASSERT_EQ(object.remaining(), 2);
}

TEST(GuesserTest, Brute_Force_test){
	Guesser object("password");
	ASSERT_FALSE(object.match("notpassword"));
	ASSERT_FALSE(object.match("1234567"));
	ASSERT_FALSE(object.match("guesssagain"));
	ASSERT_EQ(object.remaining(), 0);
}

TEST(GuesserTest, does_it_lock_on_big_dif){
	Guesser object("secret");
	ASSERT_FALSE(object.match("notasecret"));
	ASSERT_FALSE(object.match("secret"));
}