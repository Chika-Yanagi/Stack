# Stack
標準入力から与えられるスタック操作を実際に行い、最後にスタックの内容と pop された文字 列を表示するプログラム。  
  
gcc -std=c99 -o stack stack.c  
stack  
  
push a  
push b  
push c    
pop  
push d  
push e    
pop  
push f ← と入力し改行する。改行したら最後にCtrl-D を押す  
[a, b, d, f] ← 関数printstack によって表示されたスタックの内容  
ce ←スタックからpop された文字列 (関数test の 29--32行目で表示)  
  
  
