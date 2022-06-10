package main

import (
	"fmt"
)

func main() {
	// var arr [3][3]int
	// for i := 0 ; i < 3 ; i++ {
	// 	for j := 0 ; j < 3 ; j++ {
	// 		arr[i][j] = i + j
	// 	}
	// }
	// fmt.Println(arr)
	// s := "hello world"
	// for index, char := range s {
	// 	fmt.Printf("%d: %c\n", index, char)
	// }
	// var m map[string][]int
	// i := m["ho"]
	// // fmt.Println(len(i))
	// if (len(i) == 0){
	// 		fmt.Println(i)
	// }
	// arr := []int{1,2,3}
	// arr2 := []int{4,5,6}
	// arr = append(arr, arr2...)
	// fmt.Println(arr)

    n := 5
    arr := make([][]int, n)
    fmt.Println(arr)
}