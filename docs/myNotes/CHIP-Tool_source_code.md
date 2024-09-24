main.cpp 
This chip tool has a class called commands that manages all the commands  , it's the interface that manipulates all the commands 
```Cpp
// sets up the commands functions  for a given command ) then save it to a cluster ( struct)  
void RegisterCluster(const char * clusterName, commands_list commandsList); 

// save the cluster of each command (struct) and assiosiated to a help text 
void RegisterCommandSet(const char * commandSetName, commands_list commandsList, const char * helpText)

// takes an args form the terminal, process them and then runs them 
int Run(int argc, char ** argv);

int RunInteractive(const char * command, const chip::Optional<char *> & storageDirectory, bool advertiseOperational);
```

```cpp
registerCommandsDiscover(commands, &credIssuerCommands);
```
 what does this do it initializes the `commands` object with a unique pointer on function that are available  in the `discover ` class.  ``

in the `common/commands ` directory under chip-tool the are 2 classes that are the most important 
`Commands.h` and `Command.h`
the `Commands.h` we can say (GUI) takes care of the args and process them and all sort of that stuff.
The most important one is this Class `Command` it takes arguments using the `Commands.h` class  transforms them in to a command  than uses a `virtual` function to call run on that specific command. 


ShowCommandSets: show the global commands in matter 

BDX: Bluk data exchange 
