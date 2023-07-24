const express = require('express');
const router = express.Router();
const { create_todo, all_todo, todo_id, delete_task_by_id, update_task_by_id } = require('./todos.query');
const auth = require('../../middleware/auth');
const verif_id = require('../../middleware/notFound');

router.get('/', auth, getAllTodo);
router.get('/:id', auth, verif_id, getTodoById);
router.post('/', auth, createNewTodo);
router.delete('/:id', auth, deleteTodoById);
router.put('/:id', auth, updateTodoById);

function getAllTodo(req, res) {
  all_todo(res);
}

function getTodoById(req, res) {
  const id = req.params.id;
  todo_id(res, id);
}

function createNewTodo(req, res) {
  const { title, description, due_time, user_id, status } = req.body;

  if (!title || !description || !due_time || !user_id || !status) {
    return res.status(500).json({ "msg": "internal server error" });
  }

  create_todo(res, title, description, due_time, user_id, status);
}

function deleteTodoById(req, res) {
  const id = req.params.id;
  delete_task_by_id(res, id);
}

function updateTodoById(req, res) {
  const id = req.params.id;
  const { title, description, due_time, user_id, status } = req.body;

  if (!id || !title || !description || !due_time || !user_id || !status) {
    return res.status(500).json({ "msg": "internal server error" });
  }

  update_task_by_id(res, id, title, description, due_time, user_id, status);
}

module.exports = router;
const db = require('../../config/db');

exports.processData = async (res, userId) => {
  try {
    const [todos, _] = await db.execute('SELECT CAST(`id` AS VARCHAR(10)) AS `id`, `title`, `description`, DATE_FORMAT(`created_at`, "%Y-%m-%d %H:%i:%S") AS `created_at`, DATE_FORMAT(`due_time`, "%Y-%m-%d %H:%i:%S") AS `due_time`, CAST(`user_id` AS VARCHAR(10)) AS `user_id`, `status` FROM `todo` WHERE `user_id` = ?', [userId]);
    console.log('Tous les todos de l\'utilisateur :', todos);

    res.status(200).json({ msg: 'Data processed successfully' });
  } catch (error) {
    res.status(500).json({ msg: 'Internal server error' });
  }
};

const { all_user, all_todo, get_info_id_or_mail, delete_user_by_id, update_user_by_id } = require('./user.query');
const auth = require('../../middleware/auth');

module.exports = function (app, bcrypt) {
  app.get('/user', auth, (req, res) => {
    all_user(res);
  });

  app.get('/user/todos', auth, (req, res) => {
    const { user } = req;
    all_todo(res, user);
  });

  app.get('/user/:data', auth, (req, res) => {
    const { data } = req.params;
    get_info_id_or_mail(res, data);
  });

  app.delete('/user/:id', auth, (req, res) => {
    const { id } = req.params;
    delete_user_by_id(res, id);
  });

  app.put('/user/:id', auth, (req, res) => {
    const { id } = req.params;
    const { title, description, completed } = req.body;

    if (!id || !title || !description || typeof completed !== 'boolean') {
      return res.status(500).json({ "msg": "erreur interne du serveur" });
    }

    update_todo_by_id(res, id, title, description, completed);
  });
};
