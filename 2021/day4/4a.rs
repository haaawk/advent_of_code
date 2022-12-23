use std::io::{self, BufRead};

fn main() {
	let stdin = io::stdin();
	let lines: Vec<String> = stdin.lock().lines().map(|l| l.unwrap()).collect();
	let nums: Vec<i32> = lines[0].split(",").map(|x| x.parse::<i32>().unwrap()).collect();
	let mut boards: Vec<[[i32; 5]; 5]> = Vec::new();
	let mut idx = 2;
	while idx < lines.len() {
		let mut b = [[0; 5]; 5];
		for i in 0..5 {
			let mut split = lines[idx + i].split_whitespace();
			for j in 0..5 {
				b[i][j] = split.next().unwrap().parse::<i32>().unwrap();
			}
		}
		boards.push(b);
		idx += 6;
	}
	for n in nums {
		for b in &mut boards {
			for i in 0..5 {
				for j in 0..5 {
					if b[i][j] == n {
						b[i][j] = -1;
						let mut winner = true;
						for x in 0..5 {
							if b[i][x] != -1  {
								winner = false;
								break;
							}
						}
						if !winner {
							winner = true;
							for x in 0..5 {
								if b[x][j] != -1  {
									winner = false;
									break;
								}
							}
						}
						if winner {
							let mut sum = 0;
							for x in 0..5 {
								for y in 0..5 {
									sum += if b[x][y] != -1 { b[x][y] } else { 0 };
								}
							}
							println!("{}", n * sum);
							return;
						}
					}
				}
			}
		}
	}
}
