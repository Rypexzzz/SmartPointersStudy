# SmartPointersStudy1

1. Использование умного указателя
Что нужно сделать
Реализуйте класс Dog, который использует стандартный умный указатель shared_ptr для класса Toy.
Реализуйте у класса Dog метод getToy, с помощью которого собака подбирает игрушку. 
Если у собаки уже есть эта игрушка, необходимо вывести в консоль фразу: I already have this toy.
Если в данный момент игрушка находится у другой собаки, нужно вывести в консоль: Another dog is playing with this toy.
Если игрушка свободна, собака подбирает её.
Реализуйте у класса Dog метод dropToy, с помощью которого собака бросает игрушку на пол, после чего другая может подобрать её. 
Если у собаки в этот момент нет игрушки, в консоль необходимо вывести: Nothing to drop.
