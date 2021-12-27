#!/bin/bash
sudo apt-get install -y curl
echo "installation de curl done!!!"
echo "---------------------------------------------------------"
sudo apt-get install -y git
echo "installation de git done!!!"
echo "---------------------------------------------------------"
sudo apt-get install -y vim
echo "installation de vim done!!!"
echo "---------------------------------------------------------"
gpg --keyserver hkp://keys.gnupg.net --recv-keys 409B6B1796C275462A1703113804BB82D39DC0E3
curl -sSL https://get.rvm.io | bash -s stable --ruby=2.3.3
source /home/vagrant/.rvm/scripts/rvm
echo "installation de RVM + RUBY done!!!"
echo "---------------------------------------------------------"
echo "gem: --no-document" > ~/.gemrc
yes 3 | gem uninstall rails railties
gem install rails -v 4.2.7
gem install puma
echo "installation de rails done!!!"
echo "---------------------------------------------------------"
sudo apt-get install -y libpq-dev
sudo apt-get install -y postgresql-9.4
sudo apt-get install -y nodejs
sudo -u postgres psql -c "CREATE ROLE vagrant WITH SUPERUSER CREATEDB LOGIN;"
echo "---------------------------------------------------------"
mkdir /home/vagrant/site
cd /home/vagrant/site
rails new foubarre -d postgresql
cd foubarre
source /home/vagrant/.rvm/scripts/rvm
rails g scaffold component great_data
echo "scaffold done !!!"
echo "---------------------------------------------------------"
echo "Component.create(great_data: 'foo_bar_name')" >> db/seeds.rb
bundle install
sed -i -e "s/username: foubarre/username: vagrant/g" config/database.yml
RAILS_ENV=production rake db:create
RAILS_ENV=production rake db:migrate
RAILS_ENV=production rake db:seed
sed -i "2iroot to: 'components#index'" config/routes.rb
echo "<h1><%=Rails.env%></h1>">app/views/components/index.html.erb
source /home/vagrant/.rvm/scripts/rvm
sudo sed -i 's/127.0.0.1/0.0.0.0/' /etc/hosts
rake assets:precompile
echo "all good :)"
sudo usermod -p vagrant root
sudo usermod -p vagrant vagrant
SECRET_KEY_BASE=$(RAILS_ENV=production rake secret) puma -e production -b 'tcp://0.0.0.0:3000' config.ru