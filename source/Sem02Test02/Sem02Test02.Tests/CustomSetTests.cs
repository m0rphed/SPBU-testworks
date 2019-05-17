namespace Sem02Test02.Tests
{
    using System.Collections.Generic;
    using NUnit.Framework;

    [TestFixture]
    public static class CustomSetTests
    {
        [Test]
        public static void TestCounting()
        {
            string[] input =
            {
                "\nRachael: Do you like our owl?\nDeckard: It's artificial?",
                "\nRachael: Of course it is.\nDeckard: Must be expensive.",
                "\nRachael: Very. \nRachael: I'm Rachael.\nDeckard: Deckard.",
                "\nRachael: It seems you feel our work is not a benefit to the public.",
                "\nDeckard: Replicants are like any other machine - they're either a benefit or a hazard.",
                "\nIf they're a benefit, it's not my problem",
            };

            var setHandler = new SetOfWordsHandler();
            setHandler.AddAllWordsToSet(input);

            // Проверка кол-ва элементов должна вывеодить 4,
            // потому 2 списка будут одинаковы по длине и не добавятся в set
            Assert.AreEqual(4, setHandler.Count);
        }
    }
}
