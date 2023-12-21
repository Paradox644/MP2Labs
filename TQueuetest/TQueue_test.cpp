
#include "TQueue.h"
#include <gtest.h>

TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int> s(10));
}


TEST(TQueue, throws_when_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue<int> s(-10));
}

TEST(TQueue, can_copy_queue)
{
	TQueue<int> t1(12);
	t1.Push(222);
	ASSERT_NO_THROW(TQueue<int> t2(t1));
}

TEST(TQueue, copied_queue_is_equal_to_source_one)
{
	TQueue<int> t1(12);
	t1.Push(222);
	TQueue<int> t2(t1);
	ASSERT_EQ(true, t1 == t2);
}

TEST(TQueue, copied_queue_has_its_own_memory)
{
	TQueue<int> t1(5);
	TQueue<int> t2(t1);
	t2.Push(10900);
	ASSERT_EQ(false, t1 == t2);
}

TEST(TQueue, can_pop_element)
{
	TQueue<int> t(10);
	t.Push(100);
	ASSERT_EQ(100, t.Pop());
}

TEST(TQueue, can_push_element)
{
	TQueue<int> t(10);
	ASSERT_NO_THROW(t.Push(100));
}

TEST(TQueue, can_get_size)
{
	TQueue<int> t(10);
	for (size_t i = 0; i < 10; i++)
	{
		t.Push(i);
	}
	ASSERT_EQ(10, t.GetSize());
}

TEST(TQueue, can_assign_queue_to_itself)
{
	TQueue<int> t(10);
	ASSERT_NO_THROW(t = t);
}

TEST(TQueue, can_assign_queues_of_equal_size)
{
	TQueue<int> t1(11);
	TQueue<int> t2(11);
	ASSERT_NO_THROW(t1 = t2);
}

TEST(TQueue, can_assign_different_queue_size)
{
	TQueue<int> t1(5);
	TQueue<int> t2(10);
	ASSERT_NO_THROW(t1 = t2);
}
