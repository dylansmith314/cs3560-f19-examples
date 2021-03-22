//Zac Baker
//Fibonacci Number Generator

//for information on running Kotlin compaltion from cammand line: https://kotlinlang.org/docs/command-line.html


import java.io.File

fun main(args: Array<String>) {
    
    var tmp1 = 1
    var tmp2 = 1
    var sum = 1;
    var cache:MutableList<Int> = mutableListOf<Int>()
    
    print("Enter Integer Number spaces(Warning all non integer will be coverted and may be very large number)")
    val n = readLine()!!.toInt(); 
    
//Non-Recusive Implemention of Fib also loads List for cache
    cache.add(1)
    for (i in 1..n-1) {
        sum = tmp1 + tmp2
        tmp1 = tmp2
        tmp2 = sum
        cache.add(tmp1)
    }
    val recurtion = Fib(n)
    println("Fibonacci number [iteration] is: $tmp1")
    println("Fibonacci number [recursive] is: $recurtion")

//Writes sequence of fibinacci numbers up to n numbers into text file
    val cacheFile = File("fib_cache$n.txt")
    val isNewFile :Boolean = cacheFile.createNewFile()

     if(isNewFile){
        cacheFile.writeText(cache.toString())
    } else{
        println("fib_cache$n.txt already exists.\n")
    }

    
    
    println("Fibonacci number cache created for $n numbers (see fib_cache.txt)\n")
}

//Recursive funtion for Fin (not as efficient as non recursive)
fun Fib (fs:Int) : Int{
    
   if (fs == 1 || fs == 2){
        return 1
   }
    else {return Fib(fs - 1) + Fib(fs - 2)}

}