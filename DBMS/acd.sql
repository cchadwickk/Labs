create table publisher_acd
(
	publisher_name char(50) primary key,
	address char(50),
	phone number(10) 	
);
create table book_acd
(
	book_id varchar2(6) primary key,
	title char(50),
	publisher_name char(50),
	foreign key(publisher_name) references publisher_acd(publisher_name)
);
create table book_author_acd
(
	book_id varchar2(6),
	author_name char(50),
	primary key(book_id,author_name),
	foreign key(book_id) references book_acd(book_id)
);
create table library_branch_acd
(
	branch_id varchar2(6) primary key,
	branch_name char(10),
	address char(50)
);
create table book_copies_acd
(
	book_id varchar2(6),
	branch_id varchar2(6),
	no_of_copies number(2),
	primary key(book_id,branch_id),
	foreign key(book_id) references book_acd(book_id),
	foreign key(branch_id) references library_branch_acd(branch_id)
);
create table borrower_acd
(
	card_no varchar2(6) primary key,
	name char(50),
	address char(50),
	phone number(10)
);
create table book_loans_acd
(
	book_id varchar2(6),
	branch_id varchar2(6),
	card_no varchar2(6),
	date_out date,
	due_date date,
	primary key(book_id,branch_id,card_no),
	foreign key(book_id) references book_acd(book_id),
	foreign key(branch_id) references library_branch_acd(branch_id),
	foreign key(card_no) references borrower_acd(card_no)
);
