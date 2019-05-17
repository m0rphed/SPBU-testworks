namespace Sem02Test02
{
    using System.Collections.Generic;

    public class SetOfWordsHandler
    {
        // в) Реализовать приложение,
        //    принимающее массивы строк и формирующее объекты класса List,
        //    содержащее слова строки,
        //    помещающее полученные объекты в объект класса SortedSet
        //    и выводящее на экран содержимого созданного множества.

        private CustomSortedSet<string> _setOfWords;

        public int Count => _setOfWords.Count;

        public SetOfWordsHandler()
        {
            _setOfWords = new CustomSortedSet<string>(new ListComparer<string>());
        }

        public void AddAllWordsToSet(string [] input)
        {
            foreach (var str in input)
            {
                var listOfWords = new List<string>(str.Split(' '));
                _setOfWords.Add(listOfWords);
            }
        }

        public string PrintAllWords()
        {
            return _setOfWords.GetPrinableRepresentation();
        }
    }
}
