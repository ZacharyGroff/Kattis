use std::collections::HashMap;
use std::str::FromStr;
use std::io::stdin;

fn main() {
  let mut trips = get_trips();
  sort_trips(&mut trips);
  run_queries(&mut trips);
}

fn get_trips() -> HashMap<String, Vec<u64>> {
  let n = get_input_line::<u64>().unwrap()[0];
  let mut trips: HashMap<String, Vec<u64>> = HashMap::new();
  for _ in 0..n {
    let line = get_input_line::<String>().unwrap();
    update_trips(line, &mut trips)
  }

  trips
}

fn sort_trips(trips: &mut HashMap<String, Vec<u64>>) {
  for (_, vec) in trips {
    vec.sort();
  }
}

fn run_queries(trips: &mut HashMap<String, Vec<u64>>) {
  let queries = get_input_line::<u64>().unwrap()[0];
  for _ in 0..queries {
    let line = get_input_line::<String>().unwrap();
    let year = query(line, trips);
    println!("{}", year);
  }
}

fn get_input_line<T: FromStr>() -> Result<Vec<T>, <T as FromStr>::Err> {
		let mut input = String::new();
		let _ = stdin().read_line(&mut input);
		
		input.split_whitespace().map(|x| x.parse::<T>()).collect()
}

fn update_trips(line: Vec<String>, trips: &mut HashMap<String, Vec<u64>>) {
  let destination = line[0].clone();
  let year: u64 = line[1].parse().unwrap();
  let vec = trips.entry(destination).or_insert(Vec::new());
  vec.push(year);
}

fn query(line: Vec<String>, trips: &mut HashMap<String, Vec<u64>>) -> u64 {
  let destination = line[0].clone();
  let nth_trip: usize = line[1].parse().unwrap();

  let vec = trips.entry(destination).or_default();
  vec[nth_trip - 1].clone()
}
