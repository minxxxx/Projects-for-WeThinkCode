# This file should contain all the record creation needed to seed the database with its default values.
# The data can then be loaded with the rails db:seed command (or created alongside the database with db:setup).
#
# Examples:
#
#   movies = Movie.create([{ name: 'Star Wars' }, { name: 'Lord of the Rings' }])
#   Character.create(name: 'Luke', movie: movies.first)
User.install("toto", "hh@gmail.com", "test1234").save
User.install("bernard","hh@gmail.com", "42424242").save
User.install("admin", "hh@gmail.com", "root").save
