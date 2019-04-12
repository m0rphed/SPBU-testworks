namespace Sem02Test01.PriorityQueue
{
    using System;

    /// <summary>
    /// Exception is thrown when the operation cannot be performed
    /// on empty queue
    /// </summary>
    [Serializable]
    public class EmptyQueueException : ApplicationException
    {
        public EmptyQueueException()
        {
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="EmptyQueueException"/> class.
        /// </summary>
        /// <param name="message">Custom message that could be specified</param>
        public EmptyQueueException(string message)
            : base(message)
        {
        }

        public EmptyQueueException(string message, Exception inner)
            : base(message, inner)
        {
        }

        protected EmptyQueueException(
            System.Runtime.Serialization.SerializationInfo info,
            System.Runtime.Serialization.StreamingContext context)
            : base(info, context)
        {
        }
    }
}
