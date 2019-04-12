namespace Sem02Test01.PriorityQueue
{
    /// <summary>
    /// Public interface represents priority queue data structure
    /// </summary>
    /// <typeparam name="T">type of values in queue</typeparam>
    public interface IPriorityQueue<T>
    {
        /// <summary>
        /// Adds new value to the queue
        /// </summary>
        /// <param name="value">new value to add into the queue</param>
        /// <param name="priority">priority of new value</param>
        void Enqueue(T value, int priority);

        /// <summary>
        /// Removes value with highest priority from the queue
        /// </summary>
        /// <returns>value that was removed from the queue</returns>
        T Dequeue();
    }
}
