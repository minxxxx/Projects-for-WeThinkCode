# This file should contain all the record creation needed to seed the database with its default values.
# The data can then be loaded with the rails db:seed command (or created alongside the database with db:setup).
#
# commands :
# rake db:drop
# rake db:create
# rake db:migrate
# rake db:seed

user = User.register("gygydu19@gmail.com", "gygy", "test1234", "test1234")
user.save

user = User.register("admin@gmail.com", "admin", "123456789", "123456789")
user.save
user.update(:grp => 0)
