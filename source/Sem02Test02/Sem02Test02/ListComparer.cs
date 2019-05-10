namespace Sem02Test02
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;

    // а) Реализовать интерфейс IComparer<T> для объектов классов List,
    // сравнивающих 2 объекта по количеству элементов, содержащихся в списке.
    public class ListComparer<T> : IComparer<List<T>>
    {
        public int Compare(List<T> x, List<T> y)
        {
            if (x.Count < y.Count)
            {
                return 1;
            }

            if (x.Count > y.Count)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
    }
}
