#include <filesystem>
#include <iostream>

#include "NullObjectExample.h"
#include "RegularExample.h"

int main(int argc, char **argv) {

  std::cout << "Null Object Pattern Example" << std::endl;
  /** The Null Object Pattern is useful when you want the rest of the program to
   * be able to interact with instances of a class without worrying about
   * whether or not they exist.
   *
   * A null check on a logger object would be a good place to apply this
   * pattern.
   * */

  /** This example internally has a nill check for each use of the logger
   * instance.
   * */

  {
    SomeTask sometask(new ApiLogger("http://www.logging.com"));
    sometask.execute();

    SomeTask someOtherTask(
        new FileLogger("/usr/home/bin/local/savedgame/text.txt"));
    someOtherTask.execute();

    SomeTask someOtherConsoleLoggedTask(new ConsoleLogger());
    someOtherConsoleLoggedTask.execute();

    SomeTask someUnloggedTask(nullptr);
    someUnloggedTask.execute();
  }
  /** This example instantiate a null logger if there is no valid logger set.
   * This logger can have its log() method called safely, but nothing happens
   *
   * */

  {
    Refactor::SomeTask sometask(
        new Refactor::ApiLogger("http://www.logging.com"));
    sometask.execute();

    Refactor::SomeTask someOtherTask(
        new Refactor::FileLogger("/usr/home/bin/local/savedgame/text.txt"));
    someOtherTask.execute();

    Refactor::SomeTask someOtherConsoleLoggedTask(
        new Refactor::ConsoleLogger());
    someOtherConsoleLoggedTask.execute();

    Refactor::SomeTask someUnloggedTask;
    someUnloggedTask.execute();
  }
  return EXIT_SUCCESS;
}