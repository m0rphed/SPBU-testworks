namespace Sem02Test01.PriorityQueue
{
    using System.Collections.Generic;

    /// <summary>
    /// Class implements priority queue data structure on linked lists
    /// </summary>
    /// <typeparam name="T">type of values in queue</typeparam>
    public class LinkedPriorityQueue<T> : IPriorityQueue<T>
    {
        /// <summary>
        /// Priority comparison condition
        /// </summary>
        private readonly bool highPriorityValueMeansHighPriority;

        /// <summary>
        /// Doubly linked list stores all records in priority order
        /// </summary>
        private LinkedList<Record<T>> _linkedList = new LinkedList<Record<T>>();

        public LinkedPriorityQueue(bool highPriorityValueMeansHighPriority)
        {
            this.highPriorityValueMeansHighPriority = highPriorityValueMeansHighPriority;
        }

        /// <summary>
        /// Adds new value by given priority to the queue
        /// </summary>
        /// <param name="value">new value</param>
        /// <param name="priority">priority of new value</param>
        public void Enqueue(T value, int priority)
        {
            var newRecord = new Record<T> { StoredValue = value, Priority = priority };

            var current = _linkedList.First;

            if (current == null)
            {
                _linkedList.AddFirst(newRecord);
                return;
            }

            while (current != null)
            {
                var needInsert = highPriorityValueMeansHighPriority ?
                    (priority <= current.Value.Priority) :
                    (priority >= current.Value.Priority);

                if (needInsert)
                {
                    _linkedList.AddBefore(current, newRecord);
                    return;
                }

                current = current.Next;
            }

            _linkedList.AddLast(newRecord);
        }

        /// <summary>
        /// Removes value with highest priority from the queue
        /// </summary>
        /// <returns>value that was removed from the queue</returns>
        public T Dequeue()
        {
            var lastElement = _linkedList.Last;

            if (lastElement == null)
            {
                throw new EmptyQueueException("Could not dequeue");
            }

            _linkedList.RemoveLast();

            return lastElement.Value.StoredValue;
        }

        private class Record<T>
        {
            public T StoredValue;
            public int Priority;
        }
    }
}
