package main;
import "fmt";

func main() {
	var n int
	fmt.Scan(&n);

	for i:=1; i<=n; i++ {
		if i % 2 == 1 {
			fmt.Print(i);
		} else {
			fmt.Print("L");

			if i % 4 == 0 {
				fmt.Print("T");
			}

			if i % 8 == 0 {
				fmt.Print("O");
			}

			if i % 16 == 0 {
				fmt.Print("L");
			}
		}
		fmt.Println();
	}
}
