fn main() {
  let (limit, events) = get_initial_line();
  let denied_groups = get_denied_groups(limit, events);
  println!("{}", denied_groups);
}

fn get_initial_line() -> (i32, i32){
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");
  let vec = input.split_whitespace().map(|x| x.parse::<i32>().expect("parse error")).collect::<Vec<i32>>();
  
  (vec[0], vec[1])
}

fn get_denied_groups(limit: i32, events: i32) -> i32 {
  let mut denied_groups = 0;
  let mut current_people = 0;
  for _ in 0..events {
    let (action, people) = get_event_line();
    check_update(action, &mut current_people, people, limit, &mut denied_groups);
  }

  denied_groups
}

fn check_update(action: String, current_people: &mut i32, people: i32, limit: i32, denied_groups: &mut i32) {
    if action == "leave" {
      *current_people -= people;
    } else if is_denied(limit, *current_people, people) {
      *denied_groups += 1;        
    } else {
      *current_people += people;
    }
}

fn is_denied(limit: i32, current_people: i32, additional: i32) -> bool {
  limit < current_people + additional
}

fn get_event_line() -> (String, i32){
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");
  let vec: Vec<String> = input.split_whitespace().map(|x| x.to_string()).collect();
  
  let action: String = vec[0].to_string();
  let people: i32 = vec[1].parse::<i32>().unwrap();

  (action, people)
}
