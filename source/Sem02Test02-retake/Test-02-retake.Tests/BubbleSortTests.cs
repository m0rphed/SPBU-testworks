using System;

namespace Test_02_retake.Tests
{
    using System.Collections.Generic;
    using NUnit.Framework;

    [TestFixture]
    public static class BubbleSortTests
    {
        [Test]
        public static void ElementsMustBeReversed()
        {
            var sut = new List<string> { "aбв", "wxyz", "12345" };
            var comparer = new StringComparerByLength();
            BubbleSort.BubbleSortWithComparer(sut, comparer);
            Assert.AreEqual(new List<string> { "12345", "wxyz", "aбв" }, sut);
        }

        [Test]
        public static void ElementsUnchanged()
        {
            var sut = new List<string> { "Does not", "scence", "make", "any" };
            var comparer = new StringComparerByLength();
            BubbleSort.BubbleSortWithComparer(sut, comparer);
            Assert.AreEqual(new List<string> { "Does not", "scence", "make", "any" }, sut);
        }

        [Test]
        public static void SimpleSortingTest()
        {
            var sut = new List<string> { "GNU", " is for ", "GNU ", "Not ", "Unix" };
            var comparer = new StringComparerByLength();
            BubbleSort.BubbleSortWithComparer(sut, comparer);
            Assert.AreEqual(new List<string> { " is for ", "GNU ", "Not ", "Unix", "GNU" }, sut);
        }

        [Test]
        public static void SortingDigits()
        {
            var sut = new List<int> { 0, 4, 1, 5, 2, 3, 6, 8, 7, 9 };
            var comparer = new EvenOddDigitComparer();
            BubbleSort.BubbleSortWithComparer(sut, comparer);
            Assert.AreEqual(new List<int> { 1, 3, 5, 7, 9, 0, 2, 4, 6, 8 }, sut);
        }

        [Test]
        public static void SimpleNumberSort()
        {
            var sut = new List<int> { 0, 4, 1, 5, 2, 3, 6, 8, 7, 9 };
            var comparer = Comparer<int>.Default;
            BubbleSort.BubbleSortWithComparer(sut, comparer);
            Assert.AreEqual(new List<int> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, sut);
        }
    }
}
