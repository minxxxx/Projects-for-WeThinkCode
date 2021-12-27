class CreateComments < ActiveRecord::Migration
  def change
    create_table :comments do |t|
      t.text :content
      t.integer :cuicui_id
      t.datetime :created_at
      t.datetime :updated_at
      t.integer :user_id
    end

	add_reference :comments, :cuicui, foreign_key: true
	add_reference :comments, :user, foreign_key: true
  end
end
