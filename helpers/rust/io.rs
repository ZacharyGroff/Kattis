mod io {
	fn get_input_line<T: std::str::FromStr>() -> Result<Vec<T>, <T as std::str::FromStr>::Err> {
		let mut input = String::new();
		let _ = std::io::stdin().read_line(&mut input);
		
		input.split_whitespace().map(|x| x.parse::<T>()).collect()
	}
}
