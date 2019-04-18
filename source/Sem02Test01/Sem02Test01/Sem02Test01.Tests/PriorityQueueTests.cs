namespace Sem02Test01.PriorityQueue.Tests
{
    using System;
    using NUnit.Framework;

    [TestFixture]
    public class PriorityQueueTests
    {
        [Test]
        public void SimpleTestDummyQueue()
        {
            var sut = new DummyPriorityQueue<string>();

            sut.Enqueue("Priority 10", 10);
            sut.Enqueue("Priority 5 X1", 5);
            sut.Enqueue("Priority 5 X2", 5);
            sut.Enqueue("Priority 15", 15);
            sut.Enqueue("Priority 1", 1);

            Assert.AreEqual("Priority 1", sut.Dequeue());
            Assert.AreEqual("Priority 5 X1", sut.Dequeue());
            Assert.AreEqual("Priority 5 X2", sut.Dequeue());
            Assert.AreEqual("Priority 10", sut.Dequeue());
            Assert.AreEqual("Priority 15", sut.Dequeue());

            Assert.Throws<EmptyQueueException>(() =>
            {
                sut.Dequeue();
            });
        }

        [Test]
        public void SimpleTestLinkedQueue()
        {
            var sut = new LinkedPriorityQueue<string>(false);

            sut.Enqueue("Priority 10", 10);
            sut.Enqueue("Priority 5 X1", 5);
            sut.Enqueue("Priority 5 X2", 5);
            sut.Enqueue("Priority 15", 15);
            sut.Enqueue("Priority 1", 1);

            Assert.AreEqual("Priority 1", sut.Dequeue());
            Assert.AreEqual("Priority 5 X1", sut.Dequeue());
            Assert.AreEqual("Priority 5 X2", sut.Dequeue());
            Assert.AreEqual("Priority 10", sut.Dequeue());
            Assert.AreEqual("Priority 15", sut.Dequeue());

            Assert.Throws<EmptyQueueException>(() =>
            {
                sut.Dequeue();
            });
        }

        [Test]
        public void SimpleTestLinkedQueueReversedPriority()
        {
            var sut = new LinkedPriorityQueue<string>(true);
            sut.Enqueue("Priority 10", 10);
            sut.Enqueue("Priority 5 X1", 5);
            sut.Enqueue("Priority 5 X2", 5);
            sut.Enqueue("Priority 15", 15);
            sut.Enqueue("Priority 1", 1);

            Assert.AreEqual("Priority 15", sut.Dequeue());
            Assert.AreEqual("Priority 10", sut.Dequeue());
            Assert.AreEqual("Priority 5 X1", sut.Dequeue());
            Assert.AreEqual("Priority 5 X2", sut.Dequeue());
            Assert.AreEqual("Priority 1", sut.Dequeue());

            Assert.Throws<EmptyQueueException>(() =>
            {
                sut.Dequeue();
            });
        }
    }
}
