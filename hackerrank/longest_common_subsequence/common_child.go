package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strings"
    "math"
)

/*
 * Complete the 'commonChild' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

// This problem is equivalent to the longest common subsequence problem which is a fundamental
// problem in dynamic programming. Also the problem is strongly related to the
// longest increasing subsequence problem. Basically the longest increasing subsequence
// problem is exactly the same as this one if you just duplicate the array, sort it and then 
// find the longest common subsequence between the sorted and initial array. Mind blowing right !?
func commonChild(s1 string, s2 string) int32 {
    n := len(s1)
    arr := make([][]int, n + 1)
    for i := 0 ; i < n + 1 ; i++ {
        arr[i] = append(arr[i], make([]int, n + 1)...)
    }

    for i, c1 := range s1 {
        for j, c2 := range s2 {
            if (c1 == c2) {
                arr[i + 1][j + 1] = arr[i][j] + 1 
            } else { 
                arr[i + 1][j + 1] = int(math.Max(float64(arr[i][j + 1]), float64(arr[i + 1][j])))
            }
        }
    }
    return int32(arr[n][n])
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)

    s1 := readLine(reader)

    s2 := readLine(reader)

    result := commonChild(s1, s2)

    fmt.Println(result)

}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err != nil {
        panic(err)
    }
}
