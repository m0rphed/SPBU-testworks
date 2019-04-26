namespace Sem02Test01.PriorityQueue
{
    using System.Collections.Generic;

    /// <summary>
    /// Class implements priority queue data structure on sorted dictionary
    /// This implementation has no support for negative priority,
    /// in this implementation lower priority value means hiegher priority
    /// </summary>
    /// <typeparam name="T">type of values in queue</typeparam>
    public class DummyPriorityQueue<T> : IPriorityQueue<T>
    {
        private SortedDictionary<int, Queue<T>> _qs = new SortedDictionary<int, Queue<T>>();

        public T Dequeue()
        {
            foreach (var q in _qs.Values)
            {
                if (q.Count > 0)
                {
                    return q.Dequeue();
                }
            }

            throw new EmptyQueueException("Queue is empty");
        }

        public void Enqueue(T value, int priority)
        {
            if (!_qs.TryGetValue(priority, out var queue))
            {
                queue = new Queue<T>();
                _qs.Add(priority, queue);
            }

            queue.Enqueue(value);
        }
    }
}