class CreateUsers < ActiveRecord::Migration[5.1]
  def change
    create_table :users do |t|
		t.string "email"
		t.string "pseudo"
		t.string "password"
	    t.integer "grp", default: 1
      t.timestamps
    end
  end
end
