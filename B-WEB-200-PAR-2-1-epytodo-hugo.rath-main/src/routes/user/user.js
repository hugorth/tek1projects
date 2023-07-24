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
    const { email, name, firstname, password } = req.body;

    if (!id || !email || !name || !firstname || !password) {
      return res.status(500).json({ "msg": "internal server error" });
    }

    const hashedPassword = bcrypt.hashSync(password, 10);
    update_user_by_id(res, id, email, hashedPassword, name, firstname);
  });
};
