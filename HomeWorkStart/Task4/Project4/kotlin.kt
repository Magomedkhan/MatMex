// За попытку сдать задачу на паскале)
fun main(args: Array<String>) {
   var i: Int = 2;
   var j: Int = 2;
   var n: Int = Integer.valueOf(readLine());
   var result = n-1;
  for (i in 2..result) 
  {
    var k = 0;
    for (j in 2..(i-1))
      {
       if ((i % j)==0){ 
              k=k+1;
          }
      }
      if (k==0){
          println(i);
      }
  }
}